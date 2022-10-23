class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        domains = {}
        
        for domain in cpdomains:
            info = domain.split(" ")
            visits = int(info[0])
            total_domain = info[1]
            
            # now get the subdomains
            subdomains = total_domain.split(".")
            domains_to_check = []
            # check the format of the domain
            if (len(subdomains) == 2):
                domains_to_check.append(subdomains[0] + "." + subdomains[1])
                domains_to_check.append(subdomains[1])
            else: # len == 3
                domains_to_check.append(subdomains[0] + "." + subdomains[1] + "." + subdomains[2])
                domains_to_check.append(subdomains[1] + "." + subdomains[2])
                domains_to_check.append(subdomains[2])
            for d in domains_to_check:
                if d in domains:
                    domains[d] += visits
                else:
                    domains[d] = visits
                    
        result = []
        for key,val in domains.items():
            result.append(str(val) + " " + key) 
        return result
            
        
