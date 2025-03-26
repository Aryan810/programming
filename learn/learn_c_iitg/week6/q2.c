#include <stdio.h>

void inp(int * ele){
    scanf("%d", ele);
}

void calc_freq(int arr[], int freq[], int n){
    int came[n];
    int k = 0;
    for (int i=0;i<n;i++){
        int iscame = 0;
        for (int j=0;j<k;j++){
            if (arr[i] == came[j]){
                iscame = 1;
                break;
            }
        }
        if (!iscame){
            int num = 0;
            for (int j=0;j<n;j++){
                if (arr[i] == arr[j]){
                    num += 1;
                }
            }
            freq[k] = num;
            came[k] = arr[i];
            k += 1;
        }
    }
    freq[k] = -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d", arr+i);
    }

    int freq[n+1];
    calc_freq(arr, freq, n);
    
    for (int i=0;i<n;i++){
        // printf("here\n");
        if (freq[i] == -1){break;}
        printf("%d ", freq[i]);
    }
    printf("\n");

    return 0;
}