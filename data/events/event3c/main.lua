event3c = LuaEvent.new("event3c")

event3c.init = function()
	event3c = event3c:initEvent()
	
	event3c.movements = {
		function() event3c.event:moveLeft() end,
		function() event3c.event:moveUp() end,
		function() event3c.event:moveRight() end,
		function() event3c.event:moveDown() end
	}
end

