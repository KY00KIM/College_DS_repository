#include <iostream>
#include <chrono>

using namespace std;

#define N 1000000
#define MAX_VALUE 10000


void runSearch(void* pList, const size_t size, const int target, int* pLoc, bool(*searchFunc)(void*, const size_t, const int, int*))
{
	chrono::system_clock::time_point beginTime = chrono::system_clock::now();
	bool result = searchFunc(pList, size, target, pLoc);
	chrono::system_clock::time_point endTime = chrono::system_clock::now();

	chrono::duration<double> duringTime = endTime - beginTime;

	printf("Execution time: %.10lf ms\n", duringTime * 10e3);
	if (result)
		printf("Found %d at %d\n", target, *pLoc);
	else
		printf("Cannot found %d\n", target);
}

bool seqSearch(void* pList, const size_t size, const int target, int* pLoc)
{
	unsigned int i = 0;
	int* arr = (int*)pList;
	while (i < size && arr[i] != target)
	{
		i++;
	}
	*pLoc = i;

	return (arr[i] == target);
}

int getRand()
{
	return rand() % MAX_VALUE;
}




void buildHash(void* pList, size_t listSize, void** pHash, size_t* hashSize)
{
	// buildHash body
    *pHash = (int*)malloc(N*3*sizeof(int));
    *hashSize = N*3;
    int* arr = (int*)pList;
    
    //initialize array
    for(int i = 0 ; i< N*3 ; i++)
        ((int*)(*pHash))[i] = -1;
    
    
    //assign val to HashTable
    for(size_t i = 0 ; i<listSize ; i++){
        size_t idx = arr[i]*100;
        while(((int*)(*pHash))[idx] != -1 )
            ++idx;
        ((int*)(*pHash))[idx]=arr[i];
    }
    
}

bool hashSearch(void* pHash, const size_t size, const int target, int* pLoc)
{
	// hashSearch body
    for(int idx = (target * 100) ; idx < size ; idx++){
        if(((int*)pHash)[idx] == target){
            *pLoc = (int)idx;
            return true;
        }else
            idx++;
    }

    return false;
}

void deleteHash(void* pHash, const size_t size)
{
	// deleteHash body
    free(pHash);
}

int main()
{
	static int arr[N] = { 0 };

	srand(2019);
	for (int i = 0; i < N; i++)
	{
		arr[i] = getRand();
	}

	int target = getRand();
	int loc = -1;

	size_t hashSize = 0;
	// Make pHash
    void* pHash;
    
	buildHash(arr, N, (&pHash), &hashSize);

	runSearch(arr, N, target, &loc, seqSearch);

	runSearch(pHash, hashSize, target, &loc, hashSearch);

	deleteHash(pHash, hashSize);

	return 0;
}
