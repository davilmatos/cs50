#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void mergeSort(int arrayStart, int arrayEnd, pair array[], pair auxArray[]);
bool recursiveLock(int a, int b);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair auxPairs[MAX * (MAX - 1) / 2];
    mergeSort(0, candidate_count, pairs, auxPairs);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (recursiveLock(pairs[i].winner, pairs[i].loser) == true)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
// In the locked[][] array, we have to look for a candidate there has only "falses" in the column
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int countFalses = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                countFalses++;
            }

            if (countFalses == candidate_count)
            {
                printf("%s\n", candidates[i]);
                return;
            }
        }
    }
    return;
}

//thanks to https://hackr.io/blog/merge-sort-in-c
void mergeSort(int arrayStart, int arrayEnd, pair array[], pair auxArray[])
{
    //if the end is smaller ou equal to the starr, there is no array to sort, so return
    if (arrayEnd <= arrayStart)
    {
        return;
    }

    //to get the middle of the array
    int mid = (arrayStart + arrayEnd) / 2;

    //sort the left part and the right part
    mergeSort(arrayStart, mid, array, auxArray);
    mergeSort(mid + 1, arrayEnd, array, auxArray);

    //to get the pointers (the begin of each sub array) and the loop counter
    int pointerLeft = arrayStart;
    int pointerRight = mid + 1;
    int k;

    //loop and merge
    for (k = arrayStart; k <= arrayEnd; k++)
    {
        if (pointerLeft == mid + 1)
        {
            auxArray[k] = array[pointerRight];
            pointerRight++;
        }
        else if (pointerRight == arrayEnd + 1)
        {
            auxArray[k] = array[pointerLeft];
            pointerLeft++;
        }
        else if ((preferences[array[pointerLeft].winner][array[pointerLeft].loser]) >
                 (preferences[array[pointerRight].winner][array[pointerRight].loser]))
        {
            auxArray[k] = array[pointerLeft];
            pointerLeft++;
        }
        else
        {
            auxArray[k] = array[pointerRight];
            pointerRight++;
        }
    }

    //copy elements from the auxiliar array to the real array
    for (k = arrayStart; k <= arrayEnd; k++)
    {
        array[k] = auxArray[k];
    }

}

bool recursiveLock(int a, int b)
{
    if (a == b)
    {
        return false;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][a] == true)
        {
            if (recursiveLock(i, b) == false)
            {
                return false;
            }
        }
    }
    return true;
}
