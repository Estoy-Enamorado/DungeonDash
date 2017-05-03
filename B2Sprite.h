
#ifndef __PHYSICSNODES_CCPHYSICSSPRITE_H__
#define __PHYSICSNODES_CCPHYSICSSPRITE_H__

#include "cocos2d.h"
#include "ExtensionMacros.h"

USING_NS_CC;

class b2Body;

/** A CCSprite subclass that is bound to a physics body.
 It works with:
 - Chipmunk: Preprocessor macro CC_ENABLE_CHIPMUNK_INTEGRATION should be defined
 - Objective-Chipmunk: Preprocessor macro CC_ENABLE_CHIPMUNK_INTEGRATION should be defined
 - Box2d: Preprocessor macro CC_ENABLE_BOX2D_INTEGRATION should be defined
 
 Features and Limitations:
 - Scale and Skew properties are ignored.
 - Position and rotation are going to updated from the physics body
 - If you update the rotation or position manually, the physics body will be updated
 - You can't enble both Chipmunk support and Box2d support at the same time. Only one can be enabled at compile time
 * @js NA
 * @lua NA
 */
class B2Sprite : public CCSprite
{
protected:
    bool    m_bIgnoreBodyRotation;
    
    b2Body  *m_pB2Body;
    
    // Pixels to Meters ratio
    float   m_fPTMRatio;
public:
    B2Sprite();
    
    static B2Sprite* create();
    /** Creates an sprite with a texture.
     The rect used will be the size of the texture.
     The offset will be (0,0).
     */
    static B2Sprite* createWithTexture(CCTexture2D *pTexture);
    
    /** Creates an sprite with a texture and a rect.
     The offset will be (0,0).
     */
    static B2Sprite* createWithTexture(CCTexture2D *pTexture, const CCRect& rect);
    
    /** Creates an sprite with an sprite frame. */
    static B2Sprite* createWithSpriteFrame(CCSpriteFrame *pSpriteFrame);
    
    /** Creates an sprite with an sprite frame name.
     An CCSpriteFrame will be fetched from the CCSpriteFrameCache by name.
     If the CCSpriteFrame doesn't exist it will raise an exception.
     @since v0.9
     */
    static B2Sprite* createWithSpriteFrameName(const char *pszSpriteFrameName);
    
    /** Creates an sprite with an image filename.
     The rect used will be the size of the image.
     The offset will be (0,0).
     */
    static B2Sprite* create(const char *pszFileName);
    
    /** Creates an sprite with an image filename and a rect.
     The offset will be (0,0).
     */
    static B2Sprite* create(const char *pszFileName, const CCRect& rect);
    
    virtual bool isDirty();
    
    /** Keep the sprite's rotation separate from the body. */
    bool isIgnoreBodyRotation() const;
    void setIgnoreBodyRotation(bool bIgnoreBodyRotation);
    
    virtual const CCPoint& getPosition();
    virtual void getPosition(float* x, float* y);
    virtual float getPositionX();
    virtual float getPositionY();
    virtual void setPosition(const CCPoint &position);
    virtual float getRotation();
    virtual void setRotation(float fRotation);
    virtual CCAffineTransform nodeToParentTransform();
    
    /** Body accessor when using box2d */
    b2Body* getB2Body() const;
    void setB2Body(b2Body *pBody);
    
    float getPTMRatio() const;
    void setPTMRatio(float fPTMRatio);
    
protected:
    void updatePosFromPhysics();
};

#endif // __PHYSICSNODES_CCPHYSICSSPRITE_H__

