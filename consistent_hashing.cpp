#include <bits/stdc++.h>
using namespace std;

struct ConsistentHashing {

	vector<string> data, servers;

	ConsistentHashing(int numberOfServers, vector<string> data){

		this->data = data; // data stored 

		// server data 
		char serverName = 'A'; // assumption -> no more than 26 servers , use some other combinations for more 
		for(int i = 0;i<numberOfServers;i++){
			servers.push_back(to_string(serverName)); serverName++;
		}
	}

	size_t hashFunction(string &data){
		// using inbuilt c++ function 
		hash<string> hash_fn;
		return hash_fn(data);
	}

	int angleHash(string &data){
		return hashFunction(data) % 360;
	}

	void addServer(char serverName){
		// assumption 26 servers are maxLimit 
		if(servers.size() == 26) return;

		map<string,int> serverInfo;
		for(int i =0;i<servers.size();i++){
			serverInfo[servers[i]]++;
		}

		if(serverInfo.find(to_string(serverName)) == serverInfo.end()) {
			servers.push_back(to_string(serverName)); 
		}
		
	}

	void removeServer(char serverName){

		map<string,int> serverInfo;
		vector<string> newServers;

		for(int i =0;i<servers.size();i++){
			serverInfo[servers[i]]++;
		}

		if(serverInfo.find(to_string(serverName)) != serverInfo.end()){
			for(int i =0;i<servers.size();i++){
				if(servers[i] == to_string(serverName)) continue;
				newServers.push_back(to_string(serverName));
			}
		}

		this->servers = newServers;
	}

	void displayHash(){
		map<string,int> hashValues;
		for(int i = 0;i<data.size();i++){
			hashValues[data[i]] = angleHash(data[i]);
		}
		for(int i = 0;i<servers.size();i++){
			hashValues[servers[i]] = angleHash(servers[i]);
		}

		for(auto node : hashValues){
			cout << node.first << " " << node.second << endl;
		}
	}

};

int main(){

	vector<string> data = {"john", "andrew" , "rohan", "ramesh", "mitchel"};
	int numberOfServers = 3;

	ConsistentHashing* consistent_hash = new ConsistentHashing(3, data);



	return 0;
}