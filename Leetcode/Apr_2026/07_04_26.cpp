class Robot {
public:
    int w, h;
    int x, y;
    char dir = 'E'; // east initially
    int p;

    Robot(int width, int height) {
        w = width;
        h = height;

        x = 0;
        y = 0;

        p = 2*w + 2*h - 4;
    }
    
    void step(int num) {
        num = num % p;

        while(num > 0){
            if(dir == 'E'){
                int move = min(num, w - x - 1);
                x += move;
                num -= move;

                if(num) dir = 'N';
            }
            else if(dir == 'N'){
                int move = min(num, h - y - 1);
                y += move;
                num -= move;

                if(num) dir = 'W';
            }
            else if(dir == 'W'){
                int move = min(num, x);
                x -= move;
                num -= move;

                if(num) dir = 'S';
            }
            else{
                int move = min(num, y);
                y -= move;
                num -= move;

                if(num) dir = 'E';
            }
        }

        if(x == 0 && y == 0 && num == 0){
            dir = 'S';
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 'E') return "East";
        if(dir == 'W') return "West";
        if(dir == 'N') return "North";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
