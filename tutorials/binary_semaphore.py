from dataclasses import dataclass, field
from time import sleep


@dataclass
class Process:
    blocked: bool = False

    def run_cz(self) -> None:
        print(f"Proceso {self} ejecutandose en CZ")
        sleep(1)


class CriticalZone:
    def __init__(self):
        self.sem: BSEM = BSEM()
    
    def enter(self, p: Process) -> None:
        p(self.sem, p)
        if not p.blocked:
            p.run_cz()
            v(self.sem, p)

@dataclass
class BSEM:
    value: int = 1
    L: list = field(default_factory=list)  # Sleep Queue

def enqueue(L: list, process: Process) -> None:
    """Encola un proceso"""
    L.append(process)

def block(process: Process) -> None:
    """Bloquea un proceso

    Parameters
    ----------
    process : Process
        _description_
    """
    process.blocked = True

def unblock(process: Process) -> None:
    """Desbloquea un proceso

    Parameters
    ----------
    process : Process
        _description_
    """
    process.blocked = False

def p(sem: BSEM, process: Process) -> None:
    """Performs DOWN Operation

    Parameters
    ----------
    sem : BSEM
        _description_
    process : Process
        _description_
    """
    if sem.value == 1:
        sem.value = 0
    else:
        enqueue(sem.L, process)
        block(process)

def v(sem: BSEM, process: Process) -> None:
    """Performs UP Operation"""
    if not sem.L:
        sem.value = 1
    else:
        # Despertamos un proceso
        process: Process = sem.L.pop(0)
        unblock(process)

def main():
    sem: BSEM = BSEM()
    process1 = Process()
    process2 = Process()
    process3 = Process()

