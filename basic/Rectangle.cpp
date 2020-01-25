#include <bits/stdc++.h>
using namespace std;
#define ld long double

struct Point { 
    ld x, y; 
};
class Rectangle {
	private:
		Point p1; //left-bot
        Point p2; //right-top
	public:
	Rectangle(){
        p1.x = p1.y = 0;
        p2.x = p2.y = 0;
    }
    Rectangle(ld x,ld y,ld width,ld height){
        p1.x = x;
        p1.y = y;
        p2.x = x + width;
        p2.y = y + height;
    }
    ld Area() const{
        return (p2.x - p1.x) * (p2.y - p1.y);
    }
    ld Perimeter() const{
        return 2*(p2.x - p1.x + p2.y - p1.y);
    }
    ld getWidth() const{
        return (p2.x - p1.x);
    }
    ld getHeight() const{
        return (p2.y - p1.y);
    }
    ld getX() const{
        return p1.x;
    }
    ld getY() const{
        return p1.y;
    }
    void setLocation(ld x, ld y){
        p1.x = x;
        p1.y = y;
    }
    void setSize(ld width, ld height){
        p2.x = width;
        p2.y = height;
    }
    bool contains(ld x, ld y){
        return p1.x <= x && x <= p2.x && p1.y <= y && y <= p2.y;
    }
    void DBG(){
        cout << p1.x << " " << p1.y << endl;
        cout << p2.x << " " << p2.y << endl << endl;
    }
    Rectangle intersection(const Rectangle& r){
            if(this->contains(r.getX(), r.getY())) {
                if(this->contains(r.getX()+r.getWidth(), r.getY()+r.getHeight())) 
                    return Rectangle(r.getX(),r.getY(),r.getX()+r.getWidth(), r.getY()+r.getHeight());
                else return Rectangle(r.getX(), r.getY(), p2.x, p2.y);
            }else if(this->contains(r.getX(), r.getY()+r.getHeight())){
                return Rectangle(r.getX(), p1.y, p2.x, r.getY()+r.getHeight());
            }else if(this->contains(r.getX()+r.getWidth(), r.getY())){
                return Rectangle(p1.x, r.getY(), r.getX()+r.getWidth(), p2.y);
            }else if(this->contains(r.getX()+r.getWidth(), r.getY()+r.getHeight())){
                return Rectangle(p1.x, p1.y, r.getX()+r.getWidth(), r.getY()+r.getHeight());
            }else if(p1.x < r.getX() && r.getX() < p2.x && r.getY() < p1.y && p2.y < r.getY()+r.getHeight()){
                return Rectangle(r.getX(), p1.y, p2.x, p2.y);
            }else if(p1.x < r.getX() + r.getWidth() && r.getX() < p1.x && r.getY() < p1.y && p2.y < r.getY() + r.getHeight()){
                return Rectangle(p1.x, p1.y, r.getX()+r.getWidth(), p2.y);            
        }else return Rectangle(0,0,0,0);
    }
};
    

int main(){
	ios::sync_with_stdio(0);  cin.tie(0);
    ld x1,x2,x3,x4,x5,x6;
    ld y1,y2,y3,y4,y5,y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;
    Rectangle W(x1,y1,x2,y2);
    Rectangle B1(x3,y3,x4,y4);
    Rectangle B2(x5,y5,x6,y6);
    B1 = B1.intersection(W);
    B2 = B2.intersection(W);
    B1.DBG();
    B2.DBG();
    Rectangle BB = B1.intersection(B2);
    BB.DBG();
    if(B1.Area() + B2.Area() - BB.Area() < W.Area()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}