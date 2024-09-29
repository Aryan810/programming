#include <iostream>
#include <map>
#include <vector>
#define lli long long int
#define INF INFINITY
using namespace std;

int main(){

    int t;
    cin >> t;
    for (int i=0;i<t;i++){
        lli n,m,k;
        cin >> n >> m >> k;
        map<lli, lli> milkYetToCome;
        for (lli i=0;i<n;i++){
            lli d, q;
            cin >> d >> q;
            milkYetToCome[d] += q; // you can also do '='
        }

        map<lli, lli> drinkableMilk;
        lli today=0, good_day=0;

        while (today < INFINITY){

            // fetching all milk till today
            while (!(milkYetToCome.empty()) && milkYetToCome.begin()->first <= today){
                const lli di = milkYetToCome.begin()->first, ai = milkYetToCome.begin()->second;
                drinkableMilk[di] += ai;
                milkYetToCome.erase(di);
            }

            // removing all expired milk from them
            while (!drinkableMilk.empty() && drinkableMilk.begin()->first <= (today-k)){
                drinkableMilk.erase(drinkableMilk.begin());
            }

            const lli nextMilkDate = (milkYetToCome.empty()?INF:milkYetToCome.begin()->first);
            if (drinkableMilk.empty()){
                today = nextMilkDate;
                continue;
            }

            const lli freshMilkQuantity = drinkableMilk.rbegin()->second; // rbegin gives a reverse iterator pointing to the last element of the map
            const lli freshMilkDate = drinkableMilk.rbegin()->first;
            if (freshMilkQuantity >= m){
                const lli expireDate = freshMilkDate + k; // fresh till (freshMilkDate + k - 1) and expire on next day
                const lli drinkPints = freshMilkQuantity/m + today;
                
                good_day += 1;
            }else{
                lli milkDrank = 0;
                while (milkDrank<m && !drinkableMilk.empty()){
                    const lli di = drinkableMilk.begin()->first, ai = drinkableMilk.begin()->second;
                    drinkableMilk.erase(di);
                    if (milkDrank+ai < m){
                        milkDrank += ai;
                        continue;
                    }
                    const lli remMilk = ai - (m - milkDrank);
                    drinkableMilk[di] += remMilk;
                }
                if (milkDrank >= m){
                    good_day += 1;
                    today += 1;
                }
                
            }
            
        }


        

    }

    return 0;
}