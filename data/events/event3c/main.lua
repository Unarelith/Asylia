event3c = CharacterEvent.new("event3c")

event3c.init = function()
	event3c = event3c:initCharacter()
	
	event3c.actions = {
		function() ActivityManager.drawMessage(_t("event3c-0")) end,
		function() ActivityManager.drawMessage(_t("event0-1")) end
	}
	
	event3c.movements = {
		function() event3c.character:moveLeft() end,
		function() event3c.character:moveUp() end,
		function() event3c.character:moveRight() end,
		function() event3c.character:moveDown() end
	}
end

