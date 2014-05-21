dofile("data/lualibs/CharacterEvent.lua")

event0 = CharacterEvent.new("event0", 2)

event0.init = function()
	local character, event0 = event0:initCharacter();
	
	event0.movements = {
		function() character:moveLeft() end,
		function() character:moveUp() end,
		function() character:moveRight() end,
		function() character:moveDown() end
	}
end

