
/*
Neste exemplo, a função boyerMooreSearch implementa o algoritmo 
de busca Boyer-Moore. Ela recebe duas strings como entrada: o texto a 
ser pesquisado e o padrão a ser encontrado. A função retorna um vetor
 contendo as posições onde o padrão é encontrado no texto.

O algoritmo utiliza a tabela de última ocorrência para determinar 
quantos caracteres podem ser pulados em cada iteração. Ele começa a 
comparar os caracteres do padrão com o texto da direita para a esquerda. 
Caso haja uma não correspondência, ele usa a tabela de última ocorrência 
para pular o máximo de caracteres possível.

*/

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std ;



vector<int> boyerMooreSearch(const string text , const string& pattern ){

    vector<int> occurrences ;

    int n = text.length();
    int m = pattern.length();


    if(m == 0 || n < m)

        return occurrences ;

        unordered_map<char, int> lastOccurrence;

        for(int i = 0 ; i < m ; i++)

            lastOccurrence[pattern[i]] = i ;
            
            int i = m -1;
            int j = m -1;

        while(i < n){

            if(text[i] == pattern[j]){

                if(j == 0){

                    occurrences.push_back(i);
                    i += m ;
                    j = m -1 ;

                }else {
                   i--;
                   j--;     
                }
                
            }else{
                int last = lastOccurrence[text[i]];

                i += m - min(j, 1 - last);
                j = m - 1 ;
            }
        }
        return occurrences ;
        
    
}




int main(){

    string text = "ABAAABCD";
    string pattern = "ABC";

    vector<int> occ = boyerMooreSearch(text, pattern);

    if(occ.empty()){
        cout<< " PATTERN NOT FOUND ";
    }else{

        for(int i : occ)
        cout << i << " ";
    } 

    return 0 ;
}