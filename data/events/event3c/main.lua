event3c = LuaEvent.new("event3c")

event3c.init = function()
	event3c = event3c:initEvent()
	
	event3c.update = function()
		event3c.event:checkCondition(CharacterManager.player():inFrontOf(event3c.event) and Keyboard.isKeyPressedOnce(Keyboard.GameAttack))
	end
	
	event3c.addAction(function() ActivityManager.drawMessage(_t("event3c-0")) end)
	event3c.addAction(function()
		event3c.activity = ActivityManager.drawMessage(_t("event0-1"))
		event3c.activity:addCommand("Yes")
		event3c.activity:addCommand("No")
	end)
	event3c.addAction(function()
		if event3c.activity:getCmdwinPos() == 0 then
			ActivityManager.drawMessage("OK")
		elseif event3c.activity:getCmdwinPos() == 1 then
			ActivityManager.drawMessage("Pff")
		end
	end)
	
	event3c.movements = {
		function() event3c.event:moveLeft() end,
		function() event3c.event:moveUp() end,
		function() event3c.event:moveRight() end,
		function() event3c.event:moveDown() end
	}
end

