dofile("data/lualibs/CharacterEvent.lua")

event3c = {}

event3c.init = function()
	local characterEvent = CharacterEvent.new("event3c", 1)
	
	event3c.update = function()	end
	
	event3c.render = function()
		characterEvent:render()
	end
	
	event3c.action = function()
		characterEvent:action()
	end
	
	event3c.collisionAction = function() end
	
	event3c.movements = {
		function() characterEvent.character:moveLeft() end,
		function() characterEvent.character:moveUp() end,
		function() characterEvent.character:moveRight() end,
		function() characterEvent.character:moveDown() end
	}
end

