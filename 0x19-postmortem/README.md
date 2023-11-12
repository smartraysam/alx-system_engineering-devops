# 0x19. Postmortem
### `DevOps` `SysAdmin`

## Tasks
[0. My first postmortem](./README.md)

### Summary

During the timeframe of 12:00 AM to 1:50 PM GMT, the Payment Service API that allows users to make payments for creator subscriptions and content experienced a series of 500 error responses, affecting all traffic and leading to disruptions in services relying on this API. The root cause was traced back to a permission  error that was not set to reflect on the new log file that is always created daily in the log directory, initiating a chain reaction that impacted the API's functionality.

### Timeline (all GMT)

* 12:00 AM: New log file created in the log directory.
* 12:05 AM: Outage commences.
* 12:10 AM: Teams alerted about the issue.
* 12:30 AM: The issue is confirmed by the developer.
* 12:35 AM: Cause is Identified and permission issue on the directory and log file was rectified.
* 12:40 AM: The application cache was clear and the server restarted.
* 12:41 AM: Full restoration of traffic (100%).

### Root Cause & Resolution
#### Resolution

At 10:45 PM GMT, an inadvertent  change - untested in the staging environment - was  introduced to the application through the .env file such that the application will always create a new log file at the beginning of a new day to track all events, and errors that occur if that particular day. At 12:00 AM, the application creates a new log file with less written permission. Whenever the application tried to write any log event into the new log file, a permission error occurred which resulted in 500 server errors which began the service outage at 12:05AM.

#### Resolution

By 12:10 AM GMT, the engineering teams were alerted and promptly investigated the issue. At 12:30 AM, the incident response team realized that the monitoring system was exacerbating the problem caused by the permission. 

The corrective measures involved setting the permission of the log directory such that any newly created log will have the same permission as the parent directory, restarting the Apache2, and restarting the supervisor. By 12:41 AM, the payment service was fully restored.

### Corrective & Preventive Measures

In response to this incident, we have conducted an internal review to address the underlying causes and prevent future occurrences. The following measures are being implemented:
* Temporarily disable the creation of a new log file at the beginning of a new day.
* Run a permission check on the newly created file.
* Run a periodic check on the payment service.

We the engineering team, we remain dedicated to continually improving our technology and operational processes to prevent outages. We extend our gratitude for your patience and apologize for any inconvenience caused to you and your users. Your support is greatly appreciated, and we are committed to serving you better.

