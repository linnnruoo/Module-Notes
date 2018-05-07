#include <vincent.h>
#include <evilprof.h>

int main(){
    int week, studio, celc, assignment, presentation;
    int pain, tears, sleep, social_life, meal_at_McDonalds;
    bool vincent_is_working = false;

    pain = tears = meal_at_McDonalds = 0;
    social_life = sleep = INF;

    for(int week=1; week<=13; week++){
        bool whats_going_on = true;
        bool can_i_see_ur_report = true;

        meal_at_McDonalds++;

        if (week > 7){
            pain++;
            tears++;
            sleep--;
            social_life--;
            meal_at_McDonalds += 3;

            if (vincent_is_working) ? pain-- : pain++;
        }

        if(week == 13) {
            Murphys_Law_effect = true;
        }
    }


    return vincent;
}

//this code is definitely not executable

//learnt alot of stuff from this module and implemented alot of cool things on vincent
//i still love it even though it's quite painful at the start
//and no matter how horrifying the quiz was
