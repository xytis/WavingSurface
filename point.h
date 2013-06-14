
struct point{
    float x;
    float y;
    float amp;
    float velocity;

    point* neighbors[4];

    void init(float, float, float, float);
    void calculate_amp();
    void update_velocity();
    void update();
    void add_neighbor(point&);
};
