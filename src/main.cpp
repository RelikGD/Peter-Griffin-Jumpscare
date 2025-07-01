#include <Geode/Geode.hpp>

#include <Geode/modify/MenuGameLayer.hpp>

using namespace geode::prelude;

class $modify(Peter, MenuGameLayer) {
	struct Fields{
		CCSprite* Peter = nullptr;
		float opacity = 255;
	};

	void update(float dt){
		auto& Peter = this->m_fields->Peter;
		auto& opacity = this->m_fields->opacity;
	
		
		if (Peter) {
			
			this->m_fields->Peter->setOpacity(opacity);

			opacity-= 120 * dt;

			if (opacity <= 0) {
				opacity = 255.f;
				Peter->removeFromParent();
				Peter = nullptr;
			}
		}	
		MenuGameLayer::update(dt);
	}
	void destroyPlayer() {
		MenuGameLayer::destroyPlayer();

		auto& Peter = this->m_fields->Peter;

		auto director = CCDirector::get();
		
		auto scene = director->getRunningScene();
		
		
		auto winSize = director->getWinSize();

		if (!Peter)	{
		auto sprite = CCSprite::create("tuff_peter"_spr);
		
		//Das frische serbische bier pöhhhh ja bruder digga komm auf ein 1v1 in fortnite im bett
		
		sprite->setPosition(CCPoint(this->getContentWidth() /2, this->getContentHeight() / 2));
		sprite->setZOrder(scene->getHighestChildZ() +1);

		sprite->setScaleX(winSize.width / sprite->getContentWidth());
		sprite->setScaleY(winSize.height / sprite->getContentHeight());

			Peter = sprite;
			
			scene->addChild(sprite);

			auto file = Mod::get()->getResourcesDir() / "top10tuff.mp3";
			FMODAudioEngine::sharedEngine()->playEffect(file.string());
		}
		
	}

};