from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Hash import HMAC, SHA256
import binascii

# AES-128 in CBC Mode with HMAC
def aes_cbc_encrypt_with_hmac(plaintext: str, key: bytes, iv: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_plaintext = pad(plaintext.encode('utf-8'), AES.block_size)
    ciphertext = cipher.encrypt(padded_plaintext)

    # Calculate HMAC over ciphertext for integrity
    h = HMAC.new(key, digestmod=SHA256)
    h.update(ciphertext)
    hmac_tag = h.digest()

    return ciphertext + hmac_tag

def aes_cbc_decrypt_with_hmac(ciphertext: bytes, key: bytes, iv: bytes) -> str:
    hmac_tag = ciphertext[-32:]  # Extract HMAC tag
    ciphertext = ciphertext[:-32]  # Extract ciphertext

    # Verify HMAC for integrity
    h = HMAC.new(key, digestmod=SHA256)
    h.update(ciphertext)
    if hmac_tag != h.digest():
        raise ValueError("HMAC verification failed")

    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_data = cipher.decrypt(ciphertext)
    unpadded_data = unpad(decrypted_data, AES.block_size)
    return unpadded_data.decode('utf-8')

if __name__ == "__main__":
    aes_key = b'0123456789abcdef'  # 16-byte AES key
    aes_iv = b'1234567890abcdef'   # 16-byte IV

    message = "This is a secret message."

    encrypted_with_hmac = aes_cbc_encrypt_with_hmac(message, aes_key, aes_iv)
    decrypted_with_hmac = aes_cbc_decrypt_with_hmac(encrypted_with_hmac, aes_key, aes_iv)

    print("Original Message:", message)
    print("Encrypted with HMAC:", binascii.hexlify(encrypted_with_hmac).decode('utf-8'))
    print("Decrypted with HMAC:", decrypted_with_hmac)
