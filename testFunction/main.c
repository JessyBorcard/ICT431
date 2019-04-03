#include <stdio.h>
#include <windows.h>

int main() {

        FILE*fp = 0; //create a var that can handle file opening
        char name[256] = {0};
        float score = 0;
        int   a =0;
        float score_tableau [100] = {0};


        fp = fopen("Score.txt", "r");
while(!feof(fp)) {
    fscanf(fp, "%s", name);

    fscanf(fp, "%f", &score);
    if (feof(fp))
        break;
    score_tableau[a] = score;
    printf("%s_%0.3f\n", name, score);

    a++;

}
    for (int i = 0; i < 100; i++)                     //Loop for ascending ordering
    {
        for (int j = 0; j < 100; j++)             //Loop for comparing other values
        {
            if (score_tableau[j] < score_tableau[i])                //Comparing other array elements
            {
                float tmp = score_tableau[i];         //Using temporary variable for storing last value
                score_tableau[i] = score_tableau[j];            //replacing value
                score_tableau[j] = tmp;             //storing last value
            }
        }
    }

    for (int i = 0; i < 100; i++)                     //Loop for printing array data after sorting
    {
        if(score_tableau[i] != 0){
        printf(" %0.3f",score_tableau[i]);
        }
    }



    fclose(fp);

    return 0;
}