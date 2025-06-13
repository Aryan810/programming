import base64
import json5

def bitmap_extraction(base64_data):
    s = base64.b64decode(base64_data).decode('utf-8')
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
                    
           
def num_in_pcap(pcapdata):
