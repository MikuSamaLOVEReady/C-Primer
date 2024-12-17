//
// Created by ÂÞÈðµÑ on 2024/8/4.
//

#ifndef OFFER_MT_2024_4_13_01_H
#define OFFER_MT_2024_4_13_01_H


namespace MT{

    bool find(vector<vector<int>>& mt , int i , int j){
        int cur_va = mt[i][j];

        if( i+1 >= mt.size() || j+1 >= mt[0].size() ){
            return false;
        }

        if( mt[i+1][j] == cur_va && mt[i][j+1] == cur_va && mt[i+1][j+1]== cur_va ){
            return true;
        }else {
            return false;
        }
    }

    int main() {
        int n , m;
        std::cin >> n >> m ;
        vector<vector<int>> mt( n ,vector<int>(m) );

        ///¶ÁÈë¾ØÕó
        for(int i = 0 ; i<n ; ++i){
            for(int j = 0 ; j<m ; ++j){
                cin >> mt[i][j];    ///
            }
        }

        int result = 0;
        for(int i=0 ; i<n ; ++i ){
            for(int j=0 ;j<m ; ++j){
                if( find(mt , i, j) ) result++;
            }
        }
        std::cout << result << std::endl;
        return 0;
    }


}


#endif //OFFER_MT_2024_4_13_01_H
