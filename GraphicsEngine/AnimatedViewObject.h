#pragma once

#include "IViewObject.h"
#include "Animation.h"

namespace GraphicsEngine {
    class AnimatedViewObject : public IViewObject
    {
    public:
        AnimatedViewObject();
        ~AnimatedViewObject();

        void draw();

    private:
        Animation* m_Animation;
        std::vector<std::string>* m_Paths;

        void zip();
    };
}
