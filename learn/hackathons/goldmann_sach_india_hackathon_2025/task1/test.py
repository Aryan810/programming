import base64
from curses.ascii import isalnum
import struct
import json

def is_valid(base64code):
    # if (len(base64code)%4 != 0):
    #     return False
    j = len(base64code)-1
    num = 0
    while (1):
        if (base64code[j] == '='):
            num += 1
        else:
            break
        j -= 1
    if (num > 2):
        return False
    
    for k, i in enumerate(base64code):
        # print(k, i)
        if (k == len(base64code)-num):
            break
        if (not(isalnum(i) or (i=='+' or i=='/'))):
            return False
    return True

def bitmap_extraction(base64_data):
    s = base64.b64decode(base64_data).decode('utf-8', errors="ignore")
    if ("ABC{" not in s):
        return 0
    else:
        for i in range(len(s)-4):
            if (s[i:i+4] == "ABC{"):
                tmp = ""
                i = i + 4
                while 1:
                    if (s[i] >= '0' and s[i] <= '9'):
                        tmp += s[i]
                    else:
                        if (s[i] == '}'):
                            return int(tmp)
                        else:
                            return 0
                    i += 1

def check(binary: bytes):
    s = binary.decode('utf-8', errors="ignore")
    i = s.find("ABC{")
    if (i == -1):
        return 0
    else:   
        tmp = ""
        for j in range(i+4, len(s)):
            if (s[i] >= '0' and s[i] <= '9'):
                tmp += s[i]
            else:
                if (s[i] == "}"):
                    return (int(tmp)%10007) + 3
                else:
                    return 0
    return 0

def read_pcap(base64code):
    binary = base64.b64decode(base64code)
    # i = 0
    # global_header = binary[i:24+i]
    # i += 24
    # packets : bytes = b''
    # while True:
    #     if (i + 16 > len(binary)):
    #         break

    #     packet_header = binary[i:i+16]
    #     i += 16    
    #     ts_sec, ts_usec, incl_len, orig_len = struct.unpack('IIII', packet_header)
    #     packet_data = binary[i:i+incl_len]
    #     i += incl_len
    #     packets += packet_data
    return check(binary)


def mistic(base64code, addr):
    s = base64.b64decode(base64code).decode('utf-8', errors="ignore")
    r = [0]*16
    m = [0]*256
    r[15] = 256
    z = False
    lines = s.split('\n')
    i = 0
    while (1):
        line = lines[i].split(" ")

        if (line[0]=="0x01"):
            a = int(line[1], 16)
            b = int(line[2], 16)
            r[b] = a
        elif (line[0] == "0x02"):
            a = int(line[1], 16)
            b = int(line[2], 16)
            r[b] = (r[b] + r[a])%256
        elif (line[0] == "0x03"):
            a = int(line[1], 16)
            b = int(line[2], 16)
            r[b] = (r[b] - r[a])%256
        elif (line[0] == "0x04"):
            a = int(line[1], 16)
            i = a
            continue
        elif (line[0] == "0x05"):
            if (z):
                a = int(line[1], 16)
                i = a
                continue
        elif (line[0] == "0x06"):
            a = int(line[1], 16)
            b = int(line[2], 16)
            r[b] = m[a]
        elif (line[0] == "0x07"):
            a = int(line[1], 16)
            b = int(line[2], 16)
            m[b] = r[a]
        elif (line[0] == "0x08"):
            a = int(line[1], 16)
            i = a
            r[15]-=1
            m[r[15]] = i+1
            continue
        elif (line[0] == "0x09"):
            i = m[r[15]]
            r[15] += 1
        else:
            # print("here")
            break
        
        i += 1
    return m[addr]

        

# -------------------------------------
# inp = '''eyJuIjogMSwgImRhdGEiOiBbeyJwY2FwIjogImJtOTBJR0VnZG1Gc2FXUXpnR0JoY0E9PSIsICJteXN0IjogImJtOTBJR0VnZG1Gc2FXUXNiWHl6Z0hkMmhhR1Y0WTI5a1pRPT0iLCAibWVtb3J5X2FkZHJlc3MiOiAyfV19''' # all data
# print(is_valid(inp))
inp = input()
if (is_valid(inp) == False):
    # print("here1")
    print("0 0 0")
else:
    data = json.loads(base64.b64decode(inp).decode('utf-8', errors="ignore"))
    common = '''Qk02AwAAAAAAADYAAAAoAAAAEAAAABAAAAABABgAAAAAAAADAAATCwAAEwsAAAAAAAAAAAAAzOvv+fL9+Mz02vLa1s/Z2OH8ysz109Hw8u/R1+nS+uva8Obhzufd2tzW09DT5PPiyObN+fzK9Oj14tbpztvJ7OP/9+DZ8dHM7trn+dPx29zU49fY2fnOztT02ejx2/ji2ur1/tDoy8jz3/bS6PzQ+OzSyuHY//Xr/sr30NLf/erM49re+NTv8PHs0u/k6dDy4Nfb2tXL4+XZ49PN4tjh3/br4uHQ6ujn1tzp/vHu//Tt+cjz9eXL0O3X/PDS8Pn2/PDZ6uHr4+vl9/3Vyu3l6/bS+eTly93o6u3W3tjJ68j1/97m3fr9+vPIzNzk08rq/Org+/fw1+T0+d/z1e/e39fV+u/K1+jbzPzlzM7w6tz38NPiyPf2+vn90Nbx3OPn2NLN8OTi9PHl2ubL6P/51tDk9tDz3O/n79D0///W88741fji1/jR7+3t1dnuyNPr7OHj7M3x0+ro4P3w5eL45+vu5d/s9OHW0dPU0N3e4ufQ3uTR7tvk5s3h//D3z/fO+uPd7vbl/v3m7eHj0uT34OnY+Nbs9eH609XX79bLyunNy8zM0N3qy83O5PrS5Pjl4vvS39v//ePM6vTv6e7Jy8/u5cnW9/Dt/8jj4PDj9/Dt0uj52ebR8P/9z8nc/fLb5f/h2OLI6+br6t3U8O3T9srU1Pf07dbS1Of30/7i2Nz93uvY1fLs6Ov03c3f0OLM7ePQ2eDd/Pz55uDK+8nczt3l2/Xj/8nl88rxytT/zfjN09bK0N3P0svt7PDo2fXv3tf04+ba4uzjz93Q39/268vO1NTV+Ov24OjQ+Prv+N3P0eHl3O35z97Z0ePk687i6ebl0dvm2vrs0NHs9+DI6M/079zW7O3Y4f789ezV4ej77fPi5/XU5sjk2d7k2ena8sjl5Oj599zv3ufZ5tblytTY0d/b5+vd583zztLr3vfr+u/j2PrZ0vf3yOTy4NLx8ej/69zS5N7w8srV9//k6Or54NLs++ff38/R383i79Dn+OTy2ubS0e7S39n159Xs
    '''
    n = int(data['n'])
    for i in range(n):
        two = read_pcap(data['data'][i]['pcap'])
        three = mistic(data['data'][i]['myst'], int(data['data'][i]['memory_address']))
        one = bitmap_extraction(common)
        print(one, two, three)
