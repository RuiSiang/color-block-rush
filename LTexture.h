#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
class LTexture
{
public:
    static int loadnum;
    LTexture();
    bool loadFromFile( std::string path );
    //void free();
    void render( int x, int y,int width,int height);
    friend void getwidth(LTexture &l);
    friend void getheight(LTexture &l);
    void operator!() const;
    void operator-() ;
private:
    SDL_Texture* mTexture;
    int mWidth;
    int mHeight;
};
#endif // SDL_H_INCLUDED

