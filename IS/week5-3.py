from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives import hashes
from typing import Tuple

def generate_rsa_keys() -> Tuple[rsa.RSAPrivateKey, rsa.RSAPublicKey]:
    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=2048
    )
    public_key = private_key.public_key()
    return private_key, public_key

def rsa_encrypt(plaintext: str, public_key: rsa.RSAPublicKey) -> bytes:
    ciphertext = public_key.encrypt(
        plaintext.encode('utf-8'),
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return ciphertext

def rsa_decrypt(ciphertext: bytes, private_key: rsa.RSAPrivateKey) -> str:
    plaintext = private_key.decrypt(
        ciphertext,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return plaintext.decode('utf-8')

if __name__ == "__main__":
    private_key, public_key = generate_rsa_keys()
    message = "This is a secret message."

    encrypted = rsa_encrypt(message, public_key)
    decrypted = rsa_decrypt(encrypted, private_key)

    print("Original Message:", message)
    print("Encrypted:", encrypted.hex())
    print("Decrypted:", decrypted)
