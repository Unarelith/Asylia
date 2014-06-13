event0 = CharacterEvent.new("event0")

event0.init = function()
	event0 = event0:initCharacter();
	
	event0.actions = {
		function() ActivityManager.drawMessage(_t("event0-0")) end,
		function() ActivityManager.drawMessage(_t("event0-1")) end
	}
	
	event0.movements = {
		function() event0.character:moveLeft() end,
		function() event0.character:moveUp() end,
		function() event0.character:moveRight() end,
		function() event0.character:moveDown() end
	}
end

