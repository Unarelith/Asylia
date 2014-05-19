dofile("data/lualibs/CharacterEvent.lua")

event3c = {}

event3c.init = function()
	--[[event3c.character = MapManager.currentMap:getEvent("event3c")
	
	event3c.update = function()
		
	end
	
	event3c.render = function()
		event3c.character:render()
	end
	
	event3c.action = function()
		if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			event3c.character:setDirection(3 - CharacterManager.player():getDirection())
			
			local dialog = ActivityManager.newDialog()
			
			dialog:addMessage(_t("event3c-0"))
		end
	end
	
	event3c.collisionAction = function()
		
	end
	
	event3c.movements = {
		function() event3c.character:moveLeft() end,
		function() event3c.character:moveUp() end,
		function() event3c.character:moveRight() end,
		function() event3c.character:moveDown() end
	}]]--
	local characterEvent = CharacterEvent.new("event3c", 1)
	
	event3c.update = function()	end
	
	event3c.render = function()
		characterEvent:render()
	end
	
	event3c.action = function()
		characterEvent:action()
	end
	
	event3c.movements = {
		function() characterEvent.character:moveLeft() end,
		function() characterEvent.character:moveUp() end,
		function() characterEvent.character:moveRight() end,
		function() characterEvent.character:moveDown() end
	}
end

