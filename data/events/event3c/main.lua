dofile("data/lualibs/CharacterEvent.lua")

event3c = CharacterEvent.new("event3c", 1)

event3c.init = function()
	local character, event3c = event3c:initCharacter();
	
	event3c.movements = {
		function() character:moveLeft() end,
		function() character:moveUp() end,
		function() character:moveRight() end,
		function() character:moveDown() end
	}
end

