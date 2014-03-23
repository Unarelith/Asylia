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
			
			dialog:addMessage("Hello little boy, do you know that you're in a incredible world made of magic and other things you don't even know?")
			dialog:addMessage("You should prepare yourself before the adventure!")
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

