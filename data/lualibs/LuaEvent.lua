LuaEvent = {
	new = function(eventName)
		local initEvent = function(self)
			self.event = MapManager.currentMap:getEvent(eventName)
			
			self.addAction = function(self, id, actionID, ...)
				local params = ParameterList()
				local _args = {...}
				
				for i, param in pairs(_args) do
					if type(param) == "number" then
						local ipart, fpart = math.modf(param)
						if fpart == 0 then
							params:addIntParameter(param)
						else
							params:addFloatParameter(param)
						end
					elseif type(param) == "string" then
						params:addStringParameter(param)
					elseif type(param) == "boolean" then
						params:addBoolParameter(param)
					end
				end
				
				EventInterpreter.addActionToQueue(id, self.event:name(), actionID, params)
			end
			
			self.update = function() end
			
			self.render = function()
				self.event:render()
			end
			
			return self
		end
		
		return {initEvent = initEvent}
	end,
	
	-- { ACTIONS } --
	drawText = 0,
	startBattle = 1,
	askQuestion = 2
}

