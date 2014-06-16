event0 = LuaEvent.new("event0")

event0.init = function()
	event0 = event0:initEvent()
	
	event0.update = function()
		event0.event:checkCondition(CharacterManager.player():inFrontOf(event0.event) and Keyboard.isKeyPressedOnce(Keyboard.GameAttack))
	end
	
	event0.addAction(function() ActivityManager.drawMessage(_t("event0-0")) end)
	event0.addAction(function() ActivityManager.drawMessage(_t("event0-1")) end)
	
	event0.movements = {
		function() event0.event:moveLeft() end,
		function() event0.event:moveUp() end,
		function() event0.event:moveRight() end,
		function() event0.event:moveDown() end
	}
end

