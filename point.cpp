#include "point.h"

void point::init(float a, float b, float ampl, float v){
    x = a;
    y = b;
    amp = ampl;
    velocity = v;
    for(int i =0; i<4;i++){
        neighbors[i]=0;
    }
}

void point::add_neighbor(point& ptN){
    for(int i =0; i<4;i++){
        if(neighbors[i]==0){
            neighbors[i]=&ptN;
            break;
        }
    }
}

void point::update(){
    amp+=velocity;
}

void point::update_velocity(){
    //dependce on model.

    float d_amp[4];
    float d_u = 0;
    for(int i =0; i<4;i++){
        d_amp[i] = neighbors[i]->amp-amp;
        d_u+=d_amp[i];
    }
    
    d_u/=4; // amp difference averaged by neighbors

    //Tension constant T: m a_i=F=k d_u_i -> a_i = T d_u_i -> a_av=sum(a_i) -> a_av =T d_u_av.
    float T = 0.2;
    
    //Spring force, which forces the oscilation to hang around y = 0.
    float D = - 0.1 * amp; 

    //accelertion
    velocity+=(T*d_u + D);
    
    //disipation
    velocity *= 0.99;
}
