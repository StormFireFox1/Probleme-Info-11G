#include <iostream>
#include <algorithm>
#define N_MAX 1000000

using namespace std;

/* "Kefa and Company"
 *
 * În mod principal, se face cu "2-pointers", numai că se verifică câteva chestii. În primul rând,
 * folosim pair să memorăm datele și să le sortăm după cei mai puțini bani. Știind asta, vom
 * aduna cei mai mulți prieteni care nu se simt săraci cu cei mai puțini bani.
 * 
 */

pair<long long, long long> friends[N_MAX]; // first este "money", second este "friendship factor"

int main() {
    long long n, d;
    cin >> n >> d;
    long long i = 0;
    for (i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }
    sort(friends, friends + n);
    long long j = 1;
    long long currentFrienshipFactor = friends[0].second; 
    long long maximumFriendshipFactor = 0;
    for(i = 0; i < n; i++) {

        while (j < n && abs(friends[i].first - friends[j].first) < d) {
            currentFrienshipFactor += friends[j].second;
            j++;
        }

        maximumFriendshipFactor = max(maximumFriendshipFactor, currentFrienshipFactor);
        currentFrienshipFactor -= friends[i].second;
    }
    cout << maximumFriendshipFactor;
    return 0;
}