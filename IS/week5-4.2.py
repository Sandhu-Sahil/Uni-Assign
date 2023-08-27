from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
import binascii

# AES-128 in ECB Mode
def aes_ecb_encrypt(plaintext: str, key: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_ECB)
    padded_plaintext = pad(plaintext.encode('utf-8'), AES.block_size)
    ciphertext = cipher.encrypt(padded_plaintext)
    return ciphertext

def aes_ecb_decrypt(ciphertext: bytes, key: bytes) -> str:
    cipher = AES.new(key, AES.MODE_ECB)
    decrypted_data = cipher.decrypt(ciphertext)
    unpadded_data = unpad(decrypted_data, AES.block_size)
    return unpadded_data.decode('utf-8')

# AES-256 in CBC Mode
def aes_cbc_encrypt(plaintext: str, key: bytes, iv: bytes) -> bytes:
    cipher = AES.new(key, AES.MODE_CBC, iv)
    padded_plaintext = pad(plaintext.encode('utf-8'), AES.block_size)
    ciphertext = cipher.encrypt(padded_plaintext)
    return ciphertext

def aes_cbc_decrypt(ciphertext: bytes, key: bytes, iv: bytes) -> str:
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_data = cipher.decrypt(ciphertext)
    unpadded_data = unpad(decrypted_data, AES.block_size)
    return unpadded_data.decode('utf-8')

if __name__ == "__main__":
    aes_key = b'0123456789abcdef'  # 16-byte key
    aes_iv = b'1234567890abcdef'   # 16-byte IV

    message = "This is a secret message."

    # AES-128 ECB
    encrypted_ecb = aes_ecb_encrypt(message, aes_key)
    decrypted_ecb = aes_ecb_decrypt(encrypted_ecb, aes_key)

    # AES-256 CBC
    encrypted_cbc = aes_cbc_encrypt(message, aes_key, aes_iv)
    decrypted_cbc = aes_cbc_decrypt(encrypted_cbc, aes_key, aes_iv)

    print("Original Message:", message)
    print("AES-128 ECB Encrypted:", binascii.hexlify(encrypted_ecb).decode('utf-8'))
    print("AES-128 ECB Decrypted:", decrypted_ecb)
    print("AES-256 CBC Encrypted:", binascii.hexlify(encrypted_cbc).decode('utf-8'))
    print("AES-256 CBC Decrypted:", decrypted_cbc)
