#include"common.h"
int LTexture::loadnum=0;
bool LTexture::loadFromFile( std::string path )
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        newTexture = SDL_CreateTextureFromSurface( gRenderer,loadedSurface );
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        } else {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface( loadedSurface );
    }
    mTexture = newTexture;
    return mTexture != NULL;
}
LTexture::LTexture()
{
    loadnum+=1;
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}
void LTexture::operator-()
{
    if( mTexture != NULL ) {
        SDL_DestroyTexture( mTexture );
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
        loadnum-=1;
    }
}
void LTexture::render( int x, int y, int width,int height)
{
    SDL_Rect renderQuad = { x, y, width, height };
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad );
}
void getwidth(LTexture &l)
{
    l.mHeight=40;
}
void getheight(LTexture &l)
{
    l.mWidth=40;
}
void LTexture::operator!() const
{
    printf( "Failed to load arrow texture!\n" );
}

