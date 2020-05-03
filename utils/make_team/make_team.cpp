#include <random> 
#include <algorithm> 
#include <iterator> 
#include <iostream>
#include <fstream>

void inputFiles( std::vector<std::vector<std::string>> & members, std::vector<std::vector<int>> & positions){
    std::ifstream members_data("./members.txt");

    members.resize(3);
	if( members_data.is_open() ){
		std::string line;
        int member_type = 0;
		while(getline(members_data, line)){
            if(line == std::string("#leader")) member_type = 0;
            else if(line == std::string("#member13")) member_type = 1;
            else if(line == std::string("#member14")) member_type = 2;
            else{
                members[member_type].push_back(line);
            }
        }
		members_data.close();
	}


    std::ifstream position_data("./positions.txt");
    positions.resize(3);
    if( position_data.is_open() ){
		std::string line;
        for (int i = 0; i < 3; i++){
            positions[i].resize(members[0].size());
            for (int j = 0; j < members[0].size(); j++)
                position_data >> positions[i][j];
        }
	    position_data.close();
	}
}

template <class t1>
void ShuffleVector(std::vector<t1> & v){
	std::random_device rd; 
	std::mt19937 g(rd());
	shuffle(v.begin(), v.end(), g);
}

void make_Team(std::vector<std::vector<std::string>> members, std::vector<std::vector<int>> positions){
    for(auto & it : members)
        ShuffleVector<std::string>(it);
    
    std::vector<std::vector<std::vector<std::string>>> teams(members[0].size());
    std::vector<int> sumPos(3, 0);

    for(int teamI = 0; teamI < teams.size(); teamI++){
        teams[teamI].resize(3);
        for(int type = 0; type < 3; type++){
            auto & nv = teams[teamI][type];
            nv.insert(nv.end(), members[type].begin()+sumPos[type], members[type].begin()+sumPos[type]+positions[type][teamI]);
            sumPos[type] += positions[type][teamI];
        }
    }

    std::ofstream output_file("./output.txt");
    if(output_file.is_open()){
        for(int teamI = 0; teamI < teams.size(); teamI++){
            output_file << "team" << teamI+1 << "\n";
            for(int type = 0; type < 3; type++){
                for(auto member : teams[teamI][type]){
                    output_file << member << " ";
                }
                output_file << "\n";
            }
            output_file << "-----------\n" << std::endl;
        }
        output_file.close();
    }
}

int main(){
    std::vector<std::vector<std::string>> members(3);
    std::vector<std::vector<int>> positions(3);
    inputFiles(members, positions);
    make_Team(members, positions);
	return 0;
}

