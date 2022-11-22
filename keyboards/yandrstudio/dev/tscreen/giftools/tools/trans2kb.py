import hid
import sys

# for device_dict in hid.enumerate():
#     keys = list(device_dict.keys())
#     keys.sort()
#     for key in keys:
#         print("%s : %s" % (key, device_dict[key]))

vid = 0xAA96
pid = 0xBB01

dev = hid.device()

for dev_info in hid.enumerate():
    if (int(dev_info['vendor_id']) == int(vid) and int(dev_info['product_id']) == pid and int(dev_info['interface_number']) == 1):
        dev.open_path(dev_info['path'])
        print(dev_info)
        break

print(dev)


# NOTE: Change the 64 here if your board uses 32-byte RAW_EPSIZE
RAW_EPSIZE = 32
def pad_message(payload):
    return payload + b'\x00' * (RAW_EPSIZE+1 - len(payload))

def tobyte(data):
    if type(data) is bytes:
        return data
    else:
        return (data).to_bytes(1, 'big')

def tobytes(data):
    data = [0] + data
    if (len(data) > RAW_EPSIZE):
        raise IndexError
    out = b''
    for num in data:
        out += tobyte(num)
    return out

# protocol define
'''
[00] + [commond1, commond2, data1, data2, ..., data30]
'''

def trans_a_block(addr, n, data):
    in_data = tobytes([0x03, 0x03, 0x8])
    print("in_data", len(in_data), in_data)
    dev.write(tobytes([0x03, 0x96, 0x8]))

try:
    while True:
        input_s = int(input("1 for test, 2 for exit:"))
        if (input_s == 1):
            trans_a_block(1,1,1)
        if (input_s == 2):
            sys.exit()
except KeyboardInterrupt:
    # recover pre mold
    print("exit")
    sys.exit()
