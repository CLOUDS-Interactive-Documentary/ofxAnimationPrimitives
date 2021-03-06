#include "testApp.h"

#include "ofxAnimationPrimitives.h"

class SubTopComposition : public ofxAnimationPrimitives::Composition
{
public:
	
	void draw()
	{
		ofSetColor(255, 0, 0, 255 * getAlpha());
		ofRect(0, 0, ofGetWidth(), ofGetHeight() / 2);
	}
};

class SubBottomComposition : public ofxAnimationPrimitives::Composition
{
public:
	
	void draw()
	{
		ofSetColor(0, 255, 0, 255 * getAlpha());
		ofRect(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2);
	}
};

class MainComposition : public ofxAnimationPrimitives::Composition
{
public:
	
	MainComposition()
	{
		// show SubTopComposition after MainComposition apper
		on(DID_APPEAR, New<SubTopComposition>(), Duration(1, 3, 1));
		
		// show SubBottomComposition after 3 sec
		at(3, New<SubBottomComposition>(), Duration(1, 3, 1));
	}
	
	void draw()
	{
		ofSetColor(255 * getAlpha());
		ofRect(0, 0, ofGetWidth(), ofGetHeight());
	}
};

MainComposition::Ref comp;

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0);
	
	// create new composition
	comp = ofxAnimationPrimitives::Composition::New<MainComposition>();

	// start MainComposition, fadein in 5sec, total duration in 10 sec, fadeout in 3 sec.
	comp->play(5, 10, 3);
}

//--------------------------------------------------------------
void testApp::update()
{
	ofxAnimationPrimitives::CompositionRunner::defaultRunner().update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofxAnimationPrimitives::CompositionRunner::defaultRunner().draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	// replay MainComposition
	comp->reset();
	comp->play();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{
}