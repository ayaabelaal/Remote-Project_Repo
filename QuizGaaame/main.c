#include <stdio.h>
#include <stdlib.h>

        //////////////////////// Global variables
char num_of_questions = 5;
char num_of_choices = 3;
char score;

            /////////////////////////////////////////////////// functions prototype
void MakeGame();
void PlayGame(char *questions_ptr[num_of_questions], char *choices_ptr[num_of_questions][num_of_choices], char correct_answr_array[num_of_questions]);
void GetChoicesOfQuestion(char *choices_attribure [num_of_questions ][ num_of_choices] , int number_of_current_question);
void GetCorrectChoiceOfQuestion(char correct_answer_attribute [num_of_questions] ,int num_of_current_question );

        ///////////////////////////// main function
int main()
{
    char make_or_play_game;

    printf("\n\n\t\t\t**** Welcome to our Quiz Game ****\n\n");
    printf(" Do you want to : \n 1- Make a Quiz Game and play it \n 2- Play a Game. \n");
    printf("\nEnter number of your choice : "); scanf("%d",&make_or_play_game);

            //  this loop for : " if user enter number  not in range "
    while(make_or_play_game<1 || make_or_play_game>2){
        printf(" Please, Enter correct number of your choice : "); scanf("%d",&make_or_play_game);
    }

    switch (make_or_play_game)
    {
        case 1: // make a game and play it
            {
                printf("\n Number of Questions : ");scanf("%d",&num_of_questions);
                while(num_of_questions<1)
                {
                    printf(" Please,Enter positive number : "); scanf("%d",&num_of_questions);
                }

                printf("\n Number of Choices : "); scanf("%d",&num_of_choices);

                while(num_of_choices<1)
                {
                    printf(" Please,Enter positive number : "); scanf("%d",&num_of_choices);
                }

               MakeGame();
            break;
            }

        case 2: // play a game
            {
                char *prepared_questions[]={
                         "What_country_is_the_tomato_war_taking_place_in_?",
                         "Monkey_Feast_takes_place_in_......",
                         "Where_does_the_Feast_of_Silence_take_place_?",
                         "One_of_the_strangest_Denmark_celebrations_is_throwing_cinnamon_on_......_people",
                         "The_Yunamu_tribe_makes_banana_soup_with_......."  };

                char *prepared_answers[][3]={
                        {"USA", "Spain", "Australia"},
                        {"Spain", "Egypt", "Thailand"},
                        {"Bali", "Qatar", "England" },
                        {"Married", "Single", "Divorced"},
                        {"Bone_of_the_dead", "Bird's_tongue", "Noodles" }    };

                char correct_answer_prepared[]={2,3,1,2,1};

                PlayGame( prepared_questions , prepared_answers, correct_answer_prepared);
            break;
            }
    }

     printf("\t\t Your score = %d \n",score);

     if( score < (float) num_of_questions/2 )
        printf("Ya fashel ya fashel\n");

     else if (score > (float) num_of_questions/2 )
        printf("Ashtar Katkooooot\n");

     else
        printf("Talamma mesh ta7t elnos f ehna fe elsalim \n");

    return 0;
}

 /////////////////////////////////////////////////////////////////////////////////// functions declaration //////////////////////////////////////////////////////////////////

void MakeGame(){

    char *questions [num_of_questions];
    char correct_answer[num_of_questions];
    char *choices [num_of_questions ][ num_of_choices];
    char input_question[1000];

    printf("\n\t\t---Enter Questions and their choices---\n\n");
    printf("\n\tWAAAAARNING !!!! Please, Don't use any space but instead it by '_' character \n\n");
       //  takink input of everything the question will need { question , choices , correct answer}

    for (int i=0;i<num_of_questions;i++)
    {
        printf("\n Question %d) ",i+1); scanf("%s", input_question );         // take input question from user
        questions[i] = malloc(strlen(input_question));               //  allocate space for question in memory
        strcpy(questions[i],input_question);                      // put input question in question[i]

         GetChoicesOfQuestion(choices,i);
         GetCorrectChoiceOfQuestion(correct_answer,i);
    }

    PlayGame(questions,choices,correct_answer);
}

////////////////////////////////////////

void GetChoicesOfQuestion(char *choices_attribure [num_of_questions ][ num_of_choices],int number_of_current_question ){

        char input_choice[100];
     // loop for taking choices of the question

        for(int j = 0 ; j <  num_of_choices ; j++ ){
            printf("choice %d) ",j+1 );  scanf("%s", input_choice );
            choices_attribure [number_of_current_question][j] = malloc( strlen( input_choice ) ); // allocate space for the choice in memory
            strcpy( choices_attribure[number_of_current_question][j] , input_choice);
        }
}

///////////////////////////////////////////

void GetCorrectChoiceOfQuestion(char correct_answer_attribute [num_of_questions] ,int num_of_current_question ){

     // take correct choice of the question

        printf("\n Enter number of correct choice : "); scanf("%d",&correct_answer_attribute[num_of_current_question]);

        while( ( correct_answer_attribute [num_of_current_question] < 1 ) || (correct_answer_attribute[num_of_current_question] > num_of_questions ) ){
            printf(" This number isn't in the range of choices. Please, Enter number of correct choice : "); scanf("%d",&correct_answer_attribute[num_of_current_question]);
        }
}

 //////////////////////////////////////

void PlayGame(char *questions_ptr[num_of_questions], char *choices_ptr[num_of_questions][num_of_choices], char correct_answr_array[num_of_questions]){

    char player_answer;
    char counter_to_try=1;

     printf("\n*****************************************************\n");

    for (int i=0;i<num_of_questions;i++){       // i--- number of current question

        printf("\t\t %d) %s\n",i+1,questions_ptr[i]); // to print question

                // loop to print choices of current question
        for(int j=0 ; j<  num_of_choices ; j++)
            printf("  %d) %s\n",j+1,choices_ptr[i][j]);

            // get answer of the  player
        printf("\n Enter number of your choice : "); scanf("%d",&player_answer);

            // Player can try 3 times to enter number of choice in range of choices  --  1 <= player_answer <= number of choices
        counter_to_try=1;

        while( player_answer < 1 || player_answer > num_of_choices )
        {
            counter_to_try ++;

            if( counter_to_try > 3 ){
                printf("\n Tb mesh la3b ,baaaaaye\n");
                return 0;
            }
            else{
                printf("Ehna han5m ?! Enter correct number  : ");
                scanf("%d",&player_answer);
                }
        }

            // player score increasing
        if( (player_answer) == correct_answr_array[i]){
                score++;
                printf("\t**BrAvOooooo**\n\n");
            }
        printf("\t\t-----------------------\n");

    }
}
