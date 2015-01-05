#include "k_means_pp.h"

using namespace std;

int main(void)
{
  string input  = "particle.txt";
  string output = "clustered.txt";
 
  const int num_of_cluster = 5;
  const int num_of_dimension = 2;

  ofstream outfile;
  outfile.open(output.c_str());

  vector< vector<double> > points;
  if(ReadDataFromFile(input, points, num_of_dimension) == 1){
	return -1;
  }

  KmeansPlus kmeans(points, num_of_cluster, num_of_dimension-1);
  Cluster result_cluster;
  
  cout << "start clustering ..." << endl;
  kmeans.Clustering(result_cluster);
  

  for(int i = 0; i < num_of_cluster; i++){
	for(int j = 0; j < (int)result_cluster.clusters[i].size(); j++){
	  for(int k = 0; k < points[result_cluster.clusters[i][j]].size() ; k++){
		outfile << points[result_cluster.clusters[i][j]][k] << " " << flush;
	  }
	  outfile << endl;
	}
	outfile << endl; outfile << endl;
  }
 
  // cout << "Finished" << endl;
  // cout << "> Number of point:" << points_num << endl; 
  // cout << "> Number of cluster:" << num_of_cluster << endl;
  // cout << "> Number of iteration:" << step << endl;

  
  
  return 0;   
}
