import struct
def conv_32_bit_binary(num):
    return ''.join('{:0>8b}'.format(c) for c in struct.pack('!f', num))
    
def conv_64_bit_binary(num):
    return ''.join('{:0>8b}'.format(c) for c in struct.pack('!d', num))

print(conv_32_bit_binary(2.2))
print(conv_64_bit_binary(2.2))


print(conv_32_bit_binary(-5.2))
print(conv_64_bit_binary(-5.2))

