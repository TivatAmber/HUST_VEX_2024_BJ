#include "unfold.h"
#include "robot-config.h"

Unfold::Unfold(){
    state = state_fold;
    air_cylinder_folder.set(state_fold);
}

void Unfold::to_unfold(){
    if(state == state_fold){
        air_cylinder_folder.set(state_unfold);
        state = state_unfold;
    }
}
void Unfold::to_fold(){
    if(state == state_unfold){
        air_cylinder_folder.set(state_fold);
        state = state_fold;
    }
}