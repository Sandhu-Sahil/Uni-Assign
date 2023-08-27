from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives import hashes

# Simulated Certificate Authority (CA)
class CertificateAuthority:
    def __init__(self):
        self.private_key = rsa.generate_private_key(
            public_exponent=65537,
            key_size=2048
        )

    def sign_key(self, data_to_sign):
        signature = self.private_key.sign(
            data_to_sign,
            padding.PSS(
                mgf=padding.MGF1(hashes.SHA256()),
                salt_length=padding.PSS.MAX_LENGTH
            ),
            hashes.SHA256()
        )
        return signature

    def get_public_key(self):
        return self.private_key.public_key()

# Verify Public Key Signature
def verify_signature(public_key, signature, data, padding):
    try:
        public_key.verify(
            signature,
            data,
            padding,
            hashes.SHA256()
        )
        return True
    except:
        return False

if __name__ == "__main__":
    # Simulate CA and user
    ca = CertificateAuthority()
    user_public_key = ca.get_public_key()

    # Simulate data
    data = b"Hello, this is a message."
    data_digest = hashes.Hash(hashes.SHA256())
    data_digest.update(data)
    data_hash = data_digest.finalize()

    # CA signs hashed data
    signature = ca.sign_key(data_hash)

    # Verify user's public key and signature
    is_verified = verify_signature(user_public_key, signature, data_hash, padding.PSS(mgf=padding.MGF1(hashes.SHA256()), salt_length=padding.PSS.MAX_LENGTH))
    if is_verified:
        print("Public key signature is verified.")
    else:
        print("Public key signature verification failed.")
