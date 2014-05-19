chest0 = {}

chest0.init = function()
	chest0.character = MapManager.currentMap:getEvent("chest0")
	chest0.opened = false
	chest0.chestType = 1
	chest0.animationAtEnd = false
	chest0.empty = false
	
	chest0.itemID = 2;
	chest0.itemCount = 99;
	
	chest0.update = function()
		
	end
	
	chest0.render = function()
		if chest0.opened then
			if not chest0.character:animationAtEnd(chest0.chestType) then
				chest0.character:playAnimation(chest0.character:x(), chest0.character:y(), chest0.chestType)
			else
				chest0.animationAtEnd = true
				chest0.character:drawFrame(chest0.character:x(), chest0.character:y(), chest0.chestType + 3 * 4)
			end
		else
			chest0.character:drawFrame(chest0.character:x(), chest0.character:y(), chest0.chestType)
		end
	end
	
	chest0.action = function()
		if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			if CharacterManager.player():getDirection() == 3 and not chest0.opened then
				chest0.opened = true
			end
		end
		
		if chest0.animationAtEnd and not chest0.empty then
			local dialog = ActivityManager.newDialog()
			local item = ItemManager.getItem(chest0.itemID)
			
			dialog:addMessage(_t("Obtained") .. " " .. chest0.itemCount .. " " .. item:name())
			
			CharacterManager.player():inventory():addItem(chest0.itemID, chest0.itemCount)
			
			chest0.empty = true
		end
	end
	
	chest0.collisionAction = function()
		
	end
	
	chest0.movements = {
		function() end
	}
end

