/*
    Copyright (C) 2015 Stephen Braitsch [http://braitsch.io]

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once
#include "ofxDatGuiIntObject.h"

class ofxDatGuiComponent : public ofxDatGuiInteractiveObject
{
    public:
    
        ofxDatGuiComponent(string label, ofxDatGuiFont* font=nullptr);
        virtual ~ofxDatGuiComponent();
    
        vector<ofxDatGuiComponent*> children;
    
        int     getX();
        int     getY();
        string  getLabel();
        int     getPositionY();
        void    setIndex(int index);
        int     getIndex();
        void    setLabel(string label);
        void    setStripeColor(ofColor color);
        void    setAnchor(ofxDatGuiAnchor anchor);
        ofxDatGuiType getType();

        void    setEnabled(bool visible);
        bool    getEnabled();
        void    setVisible(bool visible);
        bool    getVisible();
        void    setOpacity(float opacity);
    
        virtual void draw() = 0;
        virtual void update();
        virtual bool hitTest(ofPoint m) = 0;

        virtual int  getWidth();
        virtual int  getHeight();
        virtual bool getIsExpanded();
        virtual void drawColorPicker();
        virtual void setWidth(int w);
        virtual void setOrigin(int x, int y);
        virtual void setPositionY(int y);
        virtual void setAlignment(ofxDatGuiAlignment align);

        virtual void onFocus();    
        virtual void onFocusLost();
        virtual void onKeyPressed(int key);
        virtual void onMouseEnter(ofPoint m);
        virtual void onMousePress(ofPoint m);
        virtual void onMouseDrag(ofPoint m);
        virtual void onMouseLeave(ofPoint m);
        virtual void onMouseRelease(ofPoint m);
        void onKeyPressed(ofKeyEventArgs &e);
    
    protected:
    
        int x;
        int y;
        int mIndex;
        int mAlpha;
        int mOriginY;
        bool mFocused;
        bool mVisible;
        bool mEnabled;
        bool mMouseOver;
        bool mMouseDown;
        bool mRetinaEnabled;
        string mLabel;
        int mStripeWidth;
        ofColor mStripeColor;
        ofRectangle mLabelRect;
        int mLabelAreaWidth;
        int mLabelMarginRight;
        ofxDatGuiFont* mFont;
        ofxDatGuiType mType;
        ofxDatGuiAnchor mAnchor;
        ofxDatGuiAlignment mLabelAlignment;
    
        struct {
            float width;
            float height;
            float lWidth; // label area //
            float rWidth; // component area //
            float inputX;
            float padding;
            float spacing;
        } mRow;
    
        struct {
            int width;
            int inputX;
            int inputWidth;
        } mSlider;
    
        struct {
            int x;
            int y;
            int size;
        } mIcon;
    
        struct {
            int width;
            int height;
        } mWindow;
    
        void drawLabel();
        void drawLabel(string label);
        void drawStripe();
        void drawBkgd(ofColor color=ofxDatGuiColor::ROW_BKGD, int alpha=-1);
    
};
