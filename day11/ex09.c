#include <stdio.h>

typedef struct
{
  char szName[32];
  int kor;
  int eng;
  int math;
} S_Score;

void setScoreData(S_Score *pScore)
{
  scanf("%s %d %d %d",
        //(*pScore).szName,
        pScore->szName,
        &(pScore->kor), //(*pScore).kor
        &(pScore->eng),
        &(pScore->math)
        );
}

int main()
{
  S_Score _score;

  setScoreData(&_score);

  printf("name : %s \n", _score.szName);
  printf("kor : %d \n", _score.kor);
  printf("eng : %d \n", _score.eng);
  printf("math : %d \n", _score.math);

  return 0;
}
