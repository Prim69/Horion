#include "AutoTotem.h"



AutoTotem::AutoTotem() : IModule(0x0, EXPLOITS)
{
}


AutoTotem::~AutoTotem()
{
}

const char* AutoTotem::getModuleName()
{
	return ("AutoTotem");
}

void AutoTotem::onTick(C_GameMode* gm) {
	delay++;
	if (g_Data.getLocalPlayer() != nullptr) {
		C_ItemStack* i = g_Data.getLocalPlayer()->getEquippedTotem();
		if (i->item == NULL && delay >= 4) {
			C_PlayerInventoryProxy* supplies = g_Data.getLocalPlayer()->getSupplies();
			C_Inventory* a = supplies->inventory;
			for (int i = 0; i < 36; i++) {
				C_ItemStack* test = a->getItemStack(i);
				if (test->item != NULL) {
					C_Item* yikes = *test->item;
					if (yikes->itemId == 450) {
						g_Data.getLocalPlayer()->setOffhandSlot(test);
					}

				}
			}
			delay = 0;
		}
	}
}


void AutoTotem::onEnable() {
}