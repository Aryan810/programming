int cnt = 0;
    int oper = 0;
    while (a != 0 && b != 0){
        cnt += 1;
        if (a > b){
            int val = a/b;
            if (val&1){
                oper += 2 + (val/2)*3;
                a = a%b;
                swap(a, b);
            }else{
                oper += (val/2)*3;
                a = a%b;
            }
        }else{
            int val = b/a;
            if (val&1){
                oper += 2 + (val/2)*3;
                b = b%a;
                swap(b, a);
            }else{
                oper += (val/2)*3;
                b = b%a;
            }
        }
    }