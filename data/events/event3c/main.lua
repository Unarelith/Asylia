event3c = CharacterEvent.new("event3c")

event3c.init = function()
	event3c = event3c:initCharacter()
	
	event3c.movements = {
		function() event3c.character:moveLeft() end,
		function() event3c.character:moveUp() end,
		function() event3c.character:moveRight() end,
		function() event3c.character:moveDown() end
	}
end

