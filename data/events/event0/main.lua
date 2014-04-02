event0 = {}

event0.init = function()
	event0.character = MapManager.currentMap:getEvent("event0")
	
	event0.update = function()
		
	end
	
	event0.render = function()
		
	end
	
	event0.action = function()
		if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			event0.character:setDirection(3 - CharacterManager.player():getDirection())
			
			local dialog = ActivityManager.newDialog()
			
			dialog:addMessage(_t("event0-0"))
			dialog:addMessage(_t("event0-1"))
		end
	end
	
	event0.collisionAction = function()
		
	end
	
	event0.movements = {
		function() event0.character:moveLeft() end,
		function() event0.character:moveUp() end,
		function() event0.character:moveRight() end,
		function() event0.character:moveDown() end
	}
end

