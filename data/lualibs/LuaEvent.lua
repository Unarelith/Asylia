LuaEvent = {
	new = function(eventName)
		local initEvent = function(self)
			self.event = MapManager.currentMap:getEvent(eventName)
			
			self.update = function() end
			
			self.render = function()
				self.event:render()
			end
			
			self.actions = {}
			
			self.addAction = function(func)
				local str = string.dump(func)
				self.event:addAction(str)
				table.insert(self.actions, #self.actions+1, func)
			end
			
			return self
		end
		
		return {initEvent = initEvent}
	end
}

