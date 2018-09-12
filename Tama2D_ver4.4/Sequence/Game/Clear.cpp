#include "Sequence/Game/Clear.h"
#include"Sequence/Game/Load.h"
#include"Sequence/Game/Parent.h"
#include"Image.h"
#include"Constants.h"
namespace Sequence {
	namespace Game {

		Clear::Clear():
			m_image(0),
			m_count(0){
			m_image = new Image("resource/boy3.jpg", 1, 1, 0, 0, 0);
		}


		Clear::~Clear(){
			DELETE(m_image);
		}

		Child* Clear::update(Parent* parent) {
			Child* next = this;

			m_image->setTexture();
			m_image->draw(0.f, 0.f, WINDOW_WIDTH, WINDOW_HEIGHT);
		
			TextDX* t = Root::text();
			t->print("clear!", 100, 200);
		
			m_count++;
			if (m_count > 120) {
				next = new Load();
			}
			return next;
		}
	}
}
