from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad
import binascii

def des_encrypt(plaintext: str, key: bytes) -> bytes:
    cipher = DES.new(key, DES.MODE_ECB)
    padded_plaintext = pad(plaintext.encode('utf-8'), 8)  # Pad the plaintext to a multiple of 8 bytes
    ciphertext = cipher.encrypt(padded_plaintext)
    return ciphertext

def des_decrypt(ciphertext: bytes, key: bytes) -> str:
    cipher = DES.new(key, DES.MODE_ECB)
    decrypted_data = cipher.decrypt(ciphertext)
    unpadded_data = unpad(decrypted_data, 8)  # Unpad the decrypted data
    return unpadded_data.decode('utf-8')

if __name__ == "__main__":
    key = b'abcdefgh'  # 8-byte key
    plaintext = "Hello, DES!"

    encrypted = des_encrypt(plaintext, key)
    decrypted = des_decrypt(encrypted, key)

    print("Plaintext:", plaintext)
    print("Encrypted:", binascii.hexlify(encrypted).decode('utf-8'))
    print("Decrypted:", decrypted)
