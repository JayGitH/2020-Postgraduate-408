#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	//有两个狼人，一个狼人说谎，一个好人说谎
	int n;
	cin >> n;
	vector<int> v(n+1);
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			vector<int> lie, a(n + 1, 1);
			a[i] = a[j] = -1;  //假设i、j为狼人
			for(int k = 1; k <= n; k++)
				if(v[k] * a[abs(v[k])] < 0) lie.push_back(k);
			if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	return 0;
}
