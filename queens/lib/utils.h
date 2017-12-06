float random_number(float max)
{
    /*
    Returns a random float number between 0 and max
    */
    float random;
    random = (arc4random_uniform(UINT16_MAX))/ ((float)(UINT16_MAX)) * max;
    return random;
}

void shuffle(char * rows, int n_queens)
{
    /*
    Arrange the N elements of ARRAY in random order.
    Only effective if N is much smaller than RAND_MAX;
    if this may not be the case, use a better random
    number generator.
    Source: https://stackoverflow.com/questions/6127503/shuffle-array-in-c
    size_t is a type guaranteed to hold any array index
    */
    int i, j;
    char tmp;

    for (i = n_queens-1; i >= 0; i--)
    {
        j = (int) random_number(n_queens);
        tmp = *(rows + i);
        *(rows + i) = *(rows + j);
        *(rows + j) = tmp;
    }
}

int sum_down(int n)
{
    /*
    Returns the value of the sum 1+2+3+...+n
    */
    return n*(n+1)/2;
}

unsigned char absolute(char value)
{   /*
    Returns the absolute value of a char
    */
    if(value < 0)
        return -value;
    return value;
}

int factorial(int m){
    if(m < 0){
        printf("\nFactorial of a negative number does not exist!\n");
        exit(0);
    }
    if(m >= 1) return m * factorial(m-1);
    else return 1;
}

void swap(int * vector, int i, int j){
    int temp;
    temp = vector[i];
    vector[i] = vector[j];
    vector[j] = temp;
}

void permute(int ** permutations, int * vector, int start, int end, int *counter)
{
    int i, j;
    if (start == end)
    {
        for (j = 0; j < end; j++)
        {
            permutations[*counter][j] = vector[j];
        }
        ++(*counter);
        return;
    }
    else
    {
        for (i = start; i < end; i++)
        {
            swap(vector, start, i);
            permute(permutations, vector, start+1, end, counter);
            swap(vector, start, i);
        }
    }
    return;
}